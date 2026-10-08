#!/usr/bin/env python3
"""Build docs/c-lab/index.html from the C lab programs.

Compiles every program listed in tools/c_lab_manifest.json, runs it with its
sample input, and writes the page with the code, the input and the real output.

Usage: python3 tools/build_c_lab.py
"""

import html
import json
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
LAB = ROOT / "docs" / "c-lab"
PROGRAMS = LAB / "programs"
MANIFEST = Path(__file__).resolve().parent / "c_lab_manifest.json"
CFLAGS = ["-std=c11", "-Wall", "-Wextra", "-pedantic"]

EXPERIMENTS = {
    1: ("Basics: input and output", "Write C programs to:"),
    2: ("Operators", "Write C programs to:"),
    3: ("Decision making", "Write programs using if, if-else, nested if, and switch to:"),
    4: ("Loops", "Write programs to:"),
    5: ("Functions", "Write programs using user-defined functions to:"),
    6: ("Recursion", "Write recursive programs to:"),
    7: ("Arrays", "Write programs to:"),
    8: ("Strings", "Write programs to:"),
    9: ("Matrices (2-D arrays)", "Write programs to:"),
    10: ("Pointers", "Write programs to:"),
    11: ("Dynamic memory allocation", "Write programs using:"),
    12: ("Structures, unions and files", "Write programs to:"),
    13: ("Bitwise operators, enums, command line and preprocessor", "Write programs to:"),
}


def run_program(prog, build_dir, run_dir):
    src = PROGRAMS / prog["file"]
    exe = build_dir / src.stem
    cc = subprocess.run(["cc", *CFLAGS, str(src), "-o", str(exe), "-lm"],
                        capture_output=True, text=True)
    if cc.returncode != 0 or cc.stderr.strip():
        sys.exit(f"Compile problem in {prog['file']}:\n{cc.stderr}")
    run = subprocess.run([str(exe), *prog.get("args", [])], input=prog.get("stdin", ""),
                         capture_output=True, text=True, cwd=run_dir, timeout=10)
    if run.returncode != 0:
        sys.exit(f"{prog['file']} exited with {run.returncode}:\n{run.stdout}{run.stderr}")
    return src.read_text(), run.stdout + run.stderr


def esc(text):
    return html.escape(text, quote=True)


def program_html(prog, code, output):
    pid = f"e{prog['exp']}p{prog['num']}"
    name = Path(prog["file"]).name
    args = prog.get("args", [])
    stdin = prog.get("stdin", "")
    run_cmd = f"./{Path(name).stem}" + "".join(" " + a for a in args)
    parts = [
        f'<details class="program" id="{pid}">',
        f'  <summary><span class="pnum">{prog["exp"]}.{prog["num"]}</span> {esc(prog["title"])}</summary>',
        '  <div class="pbody">',
        f'    <p class="pnote">{esc(prog["note"])}</p>',
        '    <div class="code-head">',
        f'      <span class="fname">{esc(name)}</span>',
        '      <span class="code-actions">',
        '        <button class="copy" type="button">Copy</button>',
        f'        <a href="programs/{esc(prog["file"])}" download>Download</a>',
        '      </span>',
        '    </div>',
        f'    <pre class="code"><code class="language-c">{esc(code)}</code></pre>',
        '    <div class="io">',
    ]
    if args:
        parts.append(f'      <div class="io-box"><h4>run with arguments</h4><pre>{esc(run_cmd)}</pre></div>')
    if stdin:
        parts.append(f'      <div class="io-box"><h4>sample input</h4><pre>{esc(stdin.rstrip(chr(10)))}</pre></div>')
    parts += [
        f'      <div class="io-box io-out"><h4>output</h4><pre>{esc(output.rstrip(chr(10)))}</pre></div>',
        '    </div>',
        '  </div>',
        '</details>',
    ]
    return "\n".join(parts)


def main():
    progs = json.loads(MANIFEST.read_text())
    sections = []
    with tempfile.TemporaryDirectory() as tmp:
        build_dir, run_dir = Path(tmp) / "build", Path(tmp) / "run"
        build_dir.mkdir()
        run_dir.mkdir()
        for exp, (topic, lead) in EXPERIMENTS.items():
            items = [p for p in progs if p["exp"] == exp]
            items.sort(key=lambda p: p["num"])
            blocks = []
            for prog in items:
                code, output = run_program(prog, build_dir, run_dir)
                blocks.append(program_html(prog, code, output))
            sections.append(
                f'<section class="experiment" id="exp{exp}">\n'
                f'<p class="eyebrow">experiment {exp}</p>\n'
                f'<h2>{esc(topic)}</h2>\n'
                f'<p class="lead">{esc(lead)}</p>\n'
                + "\n".join(blocks) + "\n</section>"
            )
            print(f"Experiment {exp}: {len(items)} programs OK")

    toc = "\n".join(
        f'<a href="#exp{n}"><span>{n}</span>{esc(topic)}</a>' for n, (topic, _) in EXPERIMENTS.items()
    )
    template = (Path(__file__).resolve().parent / "c_lab_template.html").read_text()
    page = template.replace("{{TOC}}", toc).replace("{{SECTIONS}}", "\n\n".join(sections))
    (LAB / "index.html").write_text(page)
    print(f"Wrote {LAB / 'index.html'} ({len(progs)} programs)")


if __name__ == "__main__":
    main()
