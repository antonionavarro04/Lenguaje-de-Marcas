var htmlContainer = document.getElementById("battery");

var battery = {
    charged : '0%',
};

anime({
    targets: battery,
    charged: '100%',
    round: 1000,
    easing: 'linear',
    duration: 10260000,
    update: function() {
        htmlContainer.innerHTML = battery.charged;
    }
});