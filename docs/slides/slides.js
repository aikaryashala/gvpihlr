(function () {
  'use strict';

  const stage = document.querySelector('.stage');
  const viewport = document.querySelector('.viewport');
  const slides = Array.from(document.querySelectorAll('.slide'));
  const counter = document.querySelector('.counter');
  const notesPanel = document.querySelector('.notes-panel');
  const notesBody = notesPanel.querySelector('.notes-body');
  const notesBtn = document.getElementById('notesBtn');
  let current = 0;

  // Footer on every slide: AI Karyashala (left), slide number, Rohini Kumar Barla (right)
  slides.forEach((slide, i) => {
    const footer = document.createElement('div');
    footer.className = 'slide-footer';
    footer.innerHTML = '<span class="brand"><img src="../assets/aikaryashala_logo.png" alt="">AI Karyashala</span><span class="num">' + (i + 1) + ' / ' + slides.length + '</span><span>Rohini Kumar Barla</span>';
    stage.appendChild(footer);
    footer.hidden = true;
    slide.footer = footer;
  });

  function fit() {
    const scale = Math.min(viewport.clientWidth / 1600, viewport.clientHeight / 900);
    stage.style.transform = 'translate(-50%, -50%) scale(' + scale + ')';
  }

  function show(i) {
    current = Math.max(0, Math.min(slides.length - 1, i));
    slides.forEach((s, j) => {
      s.classList.toggle('active', j === current);
      s.footer.hidden = j !== current;
    });
    counter.textContent = (current + 1) + ' / ' + slides.length;
    const notes = slides[current].querySelector('.notes');
    notesBody.innerHTML = notes ? notes.innerHTML : '<p>No speaker notes for this slide.</p>';
    history.replaceState(null, '', '#' + (current + 1));
  }

  function toggleNotes() {
    const open = notesPanel.classList.toggle('open');
    notesBtn.setAttribute('aria-pressed', String(open));
    fit();
  }

  function toggleFullscreen() {
    if (!document.fullscreenElement) {
      document.documentElement.requestFullscreen?.();
    } else {
      document.exitFullscreen?.();
    }
  }

  document.addEventListener('fullscreenchange', () => {
    document.body.classList.toggle('fullscreen', !!document.fullscreenElement);
    fit();
  });

  document.getElementById('prevBtn').addEventListener('click', () => show(current - 1));
  document.getElementById('nextBtn').addEventListener('click', () => show(current + 1));
  notesBtn.addEventListener('click', toggleNotes);
  document.getElementById('fullBtn').addEventListener('click', toggleFullscreen);

  document.addEventListener('keydown', (e) => {
    if (e.metaKey || e.ctrlKey || e.altKey) return;
    switch (e.key) {
      case 'ArrowRight': case 'PageDown': case ' ': e.preventDefault(); show(current + 1); break;
      case 'ArrowLeft': case 'PageUp': e.preventDefault(); show(current - 1); break;
      case 'Home': show(0); break;
      case 'End': show(slides.length - 1); break;
      case 'n': case 'N': toggleNotes(); break;
      case 'f': case 'F': toggleFullscreen(); break;
    }
  });

  // Click right/left half of the slide to move forward/back
  viewport.addEventListener('click', (e) => {
    if (e.target.closest('a')) return;
    const rect = viewport.getBoundingClientRect();
    show(e.clientX - rect.left > rect.width / 2 ? current + 1 : current - 1);
  });

  // Swipe on touch screens
  let touchX = null;
  viewport.addEventListener('touchstart', (e) => { touchX = e.touches[0].clientX; }, { passive: true });
  viewport.addEventListener('touchend', (e) => {
    if (touchX === null) return;
    const dx = e.changedTouches[0].clientX - touchX;
    if (Math.abs(dx) > 40) show(dx < 0 ? current + 1 : current - 1);
    touchX = null;
  });

  window.addEventListener('resize', fit);
  window.addEventListener('hashchange', () => show(parseInt(location.hash.slice(1), 10) - 1 || 0));

  fit();
  show(parseInt(location.hash.slice(1), 10) - 1 || 0);
})();
