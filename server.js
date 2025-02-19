const express = require('express');
const bodyParser = require('body-parser');
const { execFile } = require('child_process');
const path = require('path');

const app = express();

// Parse text/plain request bodies
app.use(bodyParser.text({ type: 'text/plain' }));

// Define the endpoint that will run the C++ program
app.post('/calculate', (req, res) => {
  // The input data from the HTML form
  const inputData = req.body;
  
  // Adjust the executable path if needed
  const executablePath = path.join(__dirname, 'elements');

  // Run the C++ executable, sending inputData to its stdin
  const process = execFile(executablePath, { encoding: 'utf8' }, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error executing elements: ${error}`);
      return res.status(500).send(stderr);
    }
    // Return the output from the executable to the client
    res.send(stdout);
  });

  // Write the input data to the executable’s standard input
  process.stdin.write(inputData);
  process.stdin.end();
});

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
