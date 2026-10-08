#!/usr/bin/env python3
"""Build docs/codexray/index.html from the sample programs in docs/codexray/samples.

Compiles and runs every sample (they take no input) and writes the page with the
code and the real output.

Usage: python3 tools/build_codexray.py
"""

import html
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
PAGE_DIR = ROOT / "docs" / "codexray"
SAMPLES = PAGE_DIR / "samples"
TEMPLATE = Path(__file__).resolve().parent / "codexray_template.html"
CFLAGS = ["-std=c11", "-Wall", "-Wextra", "-pedantic"]

# file, title, what to look at in CodeXRay
SAMPLE_LIST = [
    ("01_hello_macros.c", "Hello World with macros",
     "Open the Preprocessing stage: UNIVERSITY and YEAR are replaced by their values, and stdio.h is pulled in."),
    ("02_functions.c", "Functions",
     "Switch to Call Stack & Memory: main() calls area(), which calls square()."),
    ("03_recursion_factorial.c", "Recursion: factorial",
     "Switch to Call Stack & Memory: factorial() calls itself, so the stack grows and then shrinks."),
    ("04_array_loop.c", "Arrays and loops",
     "Open the Assembly stage: the for loop becomes compare and jump instructions."),
    ("05_pointers_swap.c", "Pointers: swap two numbers",
     "Switch to Call Stack & Memory: swap() receives the addresses of x and y, so it changes main()'s variables."),
    ("06_structure.c", "Structures",
     "Open the LLVM IR stage: the struct becomes a type with an int, a char array and an int array."),
    ("07_conditional_compilation.c", "Macros and conditional compilation",
     "Open the Preprocessing stage: SQUARE(4) becomes ((4) * (4)) and the DEBUG line is removed."),
]


def esc(text):
    return html.escape(text, quote=True)


def run(src, build_dir):
    exe = build_dir / src.stem
    cc = subprocess.run(["cc", *CFLAGS, str(src), "-o", str(exe), "-lm"], capture_output=True, text=True)
    if cc.returncode != 0 or cc.stderr.strip():
        sys.exit(f"Compile problem in {src.name}:\n{cc.stderr}")
    out = subprocess.run([str(exe)], stdin=subprocess.DEVNULL, capture_output=True, text=True, timeout=10)
    if out.returncode != 0:
        sys.exit(f"{src.name} exited with {out.returncode}")
    return out.stdout


def sample_html(num, name, title, look, code, output):
    return f"""<details class="program" id="s{num}" open>
  <summary><span class="pnum">{num}</span> {esc(title)}</summary>
  <div class="pbody">
    <p class="pnote"><strong>In CodeXRay:</strong> {esc(look)}</p>
    <div class="code-head">
      <span class="fname">{esc(name)}</span>
      <span class="code-actions">
        <button class="copy" type="button">Copy</button>
        <a href="samples/{esc(name)}" download>Download</a>
      </span>
    </div>
    <pre class="code"><code class="language-c">{esc(code)}</code></pre>
    <div class="io">
      <div class="io-box io-out"><h4>output</h4><pre>{esc(output.rstrip(chr(10)))}</pre></div>
    </div>
  </div>
</details>"""


def main():
    blocks = []
    with tempfile.TemporaryDirectory() as tmp:
        for num, (name, title, look) in enumerate(SAMPLE_LIST, start=1):
            src = SAMPLES / name
            blocks.append(sample_html(num, name, title, look, src.read_text(), run(src, Path(tmp))))
            print(f"{name} OK")
    page = TEMPLATE.read_text().replace("{{SAMPLES}}", "\n\n".join(blocks))
    (PAGE_DIR / "index.html").write_text(page)
    print(f"Wrote {PAGE_DIR / 'index.html'} ({len(blocks)} samples)")


if __name__ == "__main__":
    main()
