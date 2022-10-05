const box = document.getElementById('abc');
var a = 1;
var div_id = "";

function getid(clicked_id) {
    div_id = clicked_id;
}
function gettask() {
    var z = a.toString();
    var y = "#" + z;
    const el = document.createElement('div');
    el.classList.add('grid');
    const d1 = document.createElement("div");
    d1.classList.add('grid-head');
    d1.style.cursor = "pointer";
    d1.setAttribute('data-toggle', 'modal');
    d1.setAttribute('data-target', '#myModal2');
    d1.setAttribute('id', z);
    d1.setAttribute('onclick', 'getid(this.id)');
    const d2 = document.createElement("div");
    d2.classList.add('grid-content');
    d2.setAttribute('id', y);
    var b = document.getElementById("myform").elements[0].value;
    d1.innerText = b;
    el.appendChild(d1);
    el.appendChild(d2);
    box.appendChild(el);
    a++;
}
function getitems() {
    var b = document.getElementById("myform2").elements[0].value;
    var y = "#" + div_id;
    var d3 = document.getElementById(y);
    var d4 = document.createElement('div');
    d4.classList.add('grid-content-items');
    const check = document.createElement('input');
    check.setAttribute('type', 'checkbox');
    const l1 = document.createElement('label');
    l1.innerText = b;
    check.classList.add('checkclass');
    l1.classList.add('labelclass');
    d4.appendChild(check);
    d4.appendChild(l1);
    d3.appendChild(d4);
}