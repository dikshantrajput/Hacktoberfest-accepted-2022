const fs = require("fs");
const path = require("path");
function readDataFile() {
    const dataPath = path.join(__dirname, "..", "data.json");
    let readData = fs.readFileSync(dataPath, "utf-8");
    readData = JSON.parse(readData);
    return readData;
  }
  
  function writeDataFile(obj) {
    const dataPath = path.join(__dirname, "..", "data.json");
    let readData = readDataFile();
    readData.push(obj);
    readData = JSON.stringify(readData);
    fs.writeFileSync(dataPath, readData);
  }

  module.exports={readDataFile,writeDataFile};