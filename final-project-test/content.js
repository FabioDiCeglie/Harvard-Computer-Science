function applyReadingMode() {
  document.body.classList.add('reading-mode');
}

function removeReadingMode() {
  document.body.classList.remove('reading-mode');
}

function toggleThemeMode() {
  chrome.storage.local.get(['readingMode'], function (result) {
    if (result.readingMode) {
      removeReadingMode();
      chrome.storage.local.set({ readingMode: false });

      const elementsToRestore = document.querySelectorAll(
        '[data-reading-mode]'
      );
      elementsToRestore.forEach((element) => {
        element.style.display = element.getAttribute('data-display') || '';
        element.removeAttribute('data-display');
        element.removeAttribute('data-reading-mode');
      });
    } else {
      applyReadingMode();
      chrome.storage.local.set({ readingMode: true });

      const elementsToHide = document.querySelectorAll(
        'header, nav, footer, aside, .ads, .sidebar, .comments');

      elementsToHide.forEach((element) => {
        if (element.style.display !== 'none') {
          element.setAttribute('data-display', element.style.display);
          element.setAttribute('data-reading-mode', 'true');
          element.style.display = 'none';
        }
      });
    }
  });
}

chrome.storage.local.get(['readingMode'], function (result) {
  if (result.readingMode) {
    applyReadingMode();
  }
});

toggleThemeMode();
