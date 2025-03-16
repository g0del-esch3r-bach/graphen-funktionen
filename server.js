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
  const executablePath = path.join(__dirname, 'functions', 'edges');

  const process = execFile(executablePath, { encoding: 'utf8' }, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error executing: ${error}`);
      return res.status(500).send(stderr);
    }
    res.send(stdout);
  });

  process.stdin.write(inputData);
  process.stdin.end();
});

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
