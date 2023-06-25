const { join } = require("path");
const { createReadStream } = require("fs");
const { promisify } = require("util");
const { createServer } = require("http");
const { parse } = require("url");

const server = createServer(async (req, res) => {
  try {
    const { pathname } = parse(req.url);
    const filePath = join(process.cwd(), pathname);

    const stat = await promisify(fs.stat)(filePath);

    res.writeHead(200, {
      "Content-Type": "application/octet-stream",
      "Content-Length": stat.size,
    });

    const readStream = createReadStream(filePath);
    readStream.pipe(res);
  } catch (error) {
    console.error(error);
    res.writeHead(500, { "Content-Type": "text/plain" });
    res.end("Internal Server Error");
  }
});

module.exports = server;
