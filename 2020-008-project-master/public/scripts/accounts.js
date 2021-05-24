fetch('/database/list') // Returns a Promise for the GET request
  .then(function (response) {
    // Check if the request returned a valid code
    if (response.ok) { return response.json() } // Return the response parse as JSON if code is valid

    else { throw 'Failed to load details' }
  })
  .then(function (data) { // Display the JSON data appropriately
    if (data[7] !== null) {
      document.getElementById('createHouseBox').style.display = 'none'
      document.getElementById('inHouse').style.display = 'block'
      const h = document.getElementById('headline2')
      h.innerHTML = `Hello  ${data[1]}!`
      let totalamounttopay = 0
      let totalamountowed = 0
     
      if(data[11] !== null){
      if(data[11] === 0){
        const p = document.getElementById('imowed')
          const l = document.createElement('label')
          l.setAttribute('class', 'labello2')
          p.appendChild(l)
          l.innerHTML = 'No one'
      }else{
        for(let j =0; j< data[11].length; j++)
        {
           const p = document.getElementById('imowed')
           const l = document.createElement('label')
           l.setAttribute('class', 'labello2')
           p.appendChild(l)
           l.innerHTML = `${data[11][j][0]}: ${data[11][j][1]}`
           const q = document.createElement('br')
           p.appendChild(q)
           totalamountowed += data[11][j][1]
        }
        const p = document.getElementById('imowed')
           const l = document.createElement('label')
           l.setAttribute('class', 'labello2')
           p.appendChild(l)
           totalamountowed = totalamountowed.toFixed(2)
           l.innerHTML = `The total amount I'm owed is: ${totalamountowed}`

      }
    }

      if (data[12] !== null){
      if(data[12] === 0){
        const p = document.getElementById('iowe')
          const l = document.createElement('label')
          l.setAttribute('class', 'labello')
          p.appendChild(l)
          l.innerHTML = 'No one'
      }else{
        for(let j =0; j< data[12].length; j++)
        {
           const p = document.getElementById('iowe')
           const l = document.createElement('label')
           l.setAttribute('class', 'labello')
           p.appendChild(l)
           l.innerHTML = `${data[12][j][0]}: ${data[12][j][1]}`
           const q = document.createElement('br')
           p.appendChild(q)
           totalamounttopay += data[12][j][1]
        }
        
        const p = document.getElementById('iowe')
           const l = document.createElement('label')
           l.setAttribute('class', 'labello')
           p.appendChild(l)
           totalamounttopay = totalamounttopay.toFixed(2)
           l.innerHTML = `The total amount I have to pay is: ${totalamounttopay}`
      }
    }
      
     

    } else {
      const h = document.getElementById('headline')
      h.innerHTML = `Welcome ${data[1]}, create or join a house to get started!`
      document.getElementById('createHouseBox').style.display = 'block'
      document.getElementById('inHouse').style.display = 'none'
    }
  })
  .catch(function (e) {
    alert(e)
  })

fetch('/database/list1') // Returns a Promise for the GET request
  .then(function (response) {
    // Check if the request returned a valid code
    if (response.ok) { return response.json() } // Return the response parse as JSON if code is valid

    else { throw 'Failed to load details' }
  })
  .then(function (data) { // Display the JSON data appropriately
    // for (let i = 0; i < data[0].length; i++) {
    //   const x = document.getElementById('peopleList')
    //   if (data[2] !== data[0][i]) {
    //     const c = document.createTextNode(`${data[0][i]}`)
    //     x.appendChild(c)
    //     const p = document.createElement('br')
    //     x.appendChild(p)
    //   }

    //   const x = document.getElementById('hello')
    //   const c = document.createElement('label')
    //   x.appendChild(c)
    //   c.innerHTML = `${data[0][i]}: `
    //   const p = document.createElement('input')
    //   c.appendChild(p)
    //   p.setAttribute('name', `${data[1][i]}`)
    //   c.innerHTML = p.name 
    // }
  })
  .catch(function (e) {
    alert(e)
  })
