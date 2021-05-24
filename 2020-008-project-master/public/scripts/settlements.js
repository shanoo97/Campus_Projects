fetch('/database/list1') // Returns a Promise for the GET request
  .then(function (response) {
    // Check if the request returned a valid code
    if (response.ok) { return response.json() } // Return the response parse as JSON if code is valid

    else { throw 'Failed to load details' }
  })
  .then(function (data) { // Display the JSON data appropriately
    for (let i = 0; i < data[0].length; i++) {
      const x = document.getElementById('people')
      const c = document.createElement('option')
      if (data[2] !== data[0][i]) {
        c.text = `${data[0][i]}`
        x.options.add(c, i)
      }
    }
  })
  .catch(function (e) {
    alert(e)
  })


  const number = document.getElementById('number')

number.onkeydown = function (e) {
  if (!((e.keyCode > 95 && e.keyCode < 106) ||
      (e.keyCode > 47 && e.keyCode < 58) ||
      (e.keyCode === 110) ||
      (e.keyCode === 190) ||
      e.keyCode === 8)) {
    return false
  }
}
