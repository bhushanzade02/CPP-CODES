function performOperation() {
    const matrix1 = document.getElementById('matrix1').value;
    const matrix2 = document.getElementById('matrix2').value;
    const operation = document.getElementById('operation').value;
    const resultText = document.getElementById('resultText');
  
    if (!matrix1.trim()) {
      alert("Please enter Matrix 1.");
      return;
    }
  
    if ((operation === "add" || operation === "sub") && !matrix2.trim()) {
      alert("Please enter Matrix 2 for this operation.");
      return;
    }
  
    const data = {
      matrix1,
      matrix2,
      operation,
    };
  
    // Simulate API Call (Replace with actual API endpoint if using backend)
    fetch('http://localhost:3000/calculate', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(data),
    })
      .then(response => response.json())
      .then(data => {
        resultText.innerText = data.result || "No result.";
      })
      .catch(error => {
        resultText.innerText = `Error: ${error.message}`;
      });
  }
  