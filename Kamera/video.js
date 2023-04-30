var socket = io.connect('http://' + document.domain + ':' + location.port);
socket.on('connect', function() {
    console.log('Connected to server');
});
socket.on('disconnect', function() {
    console.log('Disconnected from server');
});
socket.on('video', function(data) {
    var img = document.getElementById('video-stream');
    img.src = 'data:image/jpeg;base64,' + btoa(String.fromCharCode.apply(null, new Uint8Array(data.image)));
});
