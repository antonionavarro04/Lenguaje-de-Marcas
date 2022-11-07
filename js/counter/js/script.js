var counter = document.getElementById("counter");

var num = 0;

const i = document.querySelector("#i");
const d = document.querySelector("#d");
const r = document.querySelector("#r");

title = document.title;

i.addEventListener("click", () => {
    num++;
    counter.innerHTML = num;
    document.title = title + " - [ " + num + " ]";
});

d.addEventListener("click", () => {
    num--;
    counter.innerHTML = num;
    document.title = title + " - [ " + num + " ]";
});

r.addEventListener("click", () => {
    num = 0;
    counter.innerHTML = num;
    document.title = title;
});