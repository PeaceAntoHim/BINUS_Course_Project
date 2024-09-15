// Select the theme toggle button
const themeToggle = document.getElementById("theme-toggle");

// Add click event to toggle between light and dark themes
themeToggle.addEventListener("click", () => {
  const currentTheme = document.body.getAttribute("data-theme");

  if (currentTheme === "dark") {
    document.body.removeAttribute("data-theme");
    themeToggle.textContent = "Switch to Night Theme";
  } else {
    document.body.setAttribute("data-theme", "dark");
    themeToggle.textContent = "Switch to Light Theme";
  }
});
