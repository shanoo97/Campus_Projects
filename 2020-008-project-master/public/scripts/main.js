const selectElement = function (element) {
  return document.querySelector(element)
}

const menuToggler = selectElement('.menu-toggle')
const body = selectElement('body')

menuToggler.addEventListener('click', function () {
  body.classList.toggle('open')
})

window.sr = ScrollReveal()

sr.reveal('.animate-left', {
  origin: 'left',
  duration: 1000,
  distance: '25rem',
  delay: 200
})

sr.reveal('.animate-right', {
  origin: 'right',
  duration: 1000,
  distance: '25rem',
  delay: 200
})

sr.reveal('.animate-top', {
  origin: 'top',
  duration: 800,
  distance: '25rem',
  delay: 200
})

sr.reveal('.animate-bottom', {
  origin: 'bottom',
  duration: 800,
  distance: '25rem',
  delay: 200
})
