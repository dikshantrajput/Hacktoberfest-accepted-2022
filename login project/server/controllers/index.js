const bcrypt = require("bcryptjs");
const { readDataFile, writeDataFile } = require("../utils.js");

 const signupController = async (req, res) => {
  let { email, number, password } = req.body;
  if (!email || !number || !password) {
    res.json({ message: "Please Provide All Details" });
    return;
  }
  password = await bcrypt.hash(password, 10);
  let obj = {
    email,
    number,
    password,
  };

  let readData = readDataFile();
  let isExist = readData.filter((item) => item.email == email);

  if (isExist.length == 0) {
    writeDataFile(obj);
    res.json({ message: "Register Successfully 💯 !!!", data: obj });
    return;
  }
  res.json({ message: " User All Already Exist 😲 " });
  return;
};

 const loginController = async (req, res) => {
  let { email, password } = req.body;
  if (!email || !password) {
    res.json({ message: "Please Provide All Details" });
    return;
  }
  let readData = await readDataFile();

  let isExist = readData.filter((item) => item.email == email);
  if (isExist.length != 0) {
    let cpassword = isExist[0].password;
    let isMatch = await bcrypt.compare(password, cpassword);
    if (isMatch) {
      res.json({ message: " Conratulation You Are Login !!! " });
      return;
    } else {
      res.json({ message: " Please Try Again 😲 " });
      return;
    }
  }
  res.json({ message: " First Signup Than Try Login 😲 " });
  return;
};


module.exports={signupController,loginController}