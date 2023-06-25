const { createServer } = require("http");
const { join } = require("path");
const { createReadStream } = require("fs");

const server = createServer((req, res) => {
  const filePath = join(__dirname, "..", req.url);

  const fileStream = createReadStream(filePath);
  fileStream.pipe(res);
});

module.exports = server;
