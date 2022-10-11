const express= require("express");
const app = express();
const PORT = process.env.PORT || 3000 ;
require("dotenv").config();
app.use(express.json());
app.use(express.urlencoded({extended:true}));
app.use(require("./routes/routes"));
app.listen(PORT,()=>{
    console.log(`Server is Listen on PORT : ${PORT}`);
});