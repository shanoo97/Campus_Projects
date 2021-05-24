fetch('/database/list') // Returns a Promise for the GET request
  .then(function (response) {
    // Check if the request returned a valid code
    if (response.ok) { return response.json() } // Return the response parse as JSON if code is valid

    else { throw 'Failed to load details' }
  })
  .then(function (data) { // Display the JSON data appropriately
    const email = document.getElementById('email')
    email.placeholder = `${data[2]}`
    const name = document.getElementById('name')
    name.placeholder = `${data[4]}`
    const password = document.getElementById('password')
    password.placeholder = `${data[3]}`
    const surname = document.getElementById('surname')
    surname.placeholder = `${data[5]}`
    const username = document.getElementById('username')
    username.placeholder = `${data[1]}`
  })
  .catch(function (e) {
    alert(e)
  })
