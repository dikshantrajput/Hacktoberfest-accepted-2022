const express = require("express");
const router = express.Router();
const bcrypt = require("bcryptjs");
const { signupController, loginController } = require("../controllers/index");

router.post("/signup", signupController);

router.post("/login", loginController);
module.exports = router;
