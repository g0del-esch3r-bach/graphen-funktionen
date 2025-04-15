const express = require('express');
const bodyParser = require('body-parser');
const { execFile } = require('child_process');
const path = require('path');

const app = express();

// Serve index.html for the root route
app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

// Parse text/plain request bodies
app.use(bodyParser.text({ type: 'text/plain' }));

app.post('/calculate', (req, res) => {
  const inputData = req.body;
  const executables = ['avgdist', 'cancho', 'edges', 'efficiency', 'eigen2'];
  const results = {};
  let completed = 0;

  executables.forEach(execName => {
    const executablePath = path.join(__dirname, 'functions', process.platform === 'win32' ? execName + '.exe' : execName);
    execFile(executablePath, { encoding: 'utf8' }, (error, stdout, stderr) => {
      if (error) {
        results[execName] = "Error: " + stderr;
      } else {
        results[execName] = stdout.trim();
      }
      completed++;
      // When all processes have completed, send the JSON response.
      if (completed === executables.length) {
        res.json(results);
      }
    }).stdin.end(inputData);
  });
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
