fetch('/database/login-error') // Returns a Promise for the GET request
  .then(function (response) {
    // Check if the request returned a valid code
    if (response.ok) { return response.json() } // Return the response parse as JSON if code is valid

    else { throw 'Failed to load details' }
  })
  .then(function (data) { 
    if(data[0]===true){
        form = document.getElementById('login')
        let text=document.createTextNode("Invalid Credentials")
        let label= document.createElement('div')
        label.setAttribute('class','label-error')
        label.appendChild(text)
        form.appendChild(label)
    }
    }


  )
  .catch(function (e) {
    alert(e)
  })
