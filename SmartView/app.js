const express = require("express"),
  passport = require("passport"),
  bodyParse = require("body-parser");

const PORT = process.env.PORT || 5000;

const app = express();
app.set("view engine", "ejs");

app.use(express.static("public"));

app.use(bodyParse.urlencoded({ extended: true }));

app.get("/", (req, res) => {
  res.render("smartView");
});

app.get("/login", (req, res) => {
  res.render("login");
});

app.post("/login", (req, res) => {
  if (req.body.username == "Beto" && req.body.password == "choco"){
    res.redirect("/");
  }
  else{
    res.redirect("/login");
  }
});


require("./routes/MQTT/mqttRoutes")(app);

app.listen(PORT, () => {
  console.log(`Listening on port: ${PORT}`);
});
