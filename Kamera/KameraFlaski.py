from flask import Flask, render_template
from flask_socketio import SocketIO, emit
import io
import time
import picamera

app = Flask(__name__)
app.config['SECRET_KEY'] = 'secret!'
socketio = SocketIO(app)

# Funktion, um das Kamerabild in einen Byte-Stream zu schreiben
def gen(camera):
    stream = io.BytesIO()
    for _ in camera.capture_continuous(stream, 'jpeg', use_video_port=True):
        stream.seek(0)
        yield stream.read()
        stream.seek(0)
        stream.truncate()

# Flask Route zur Anzeige der HTML-Seite mit dem Videostream
@app.route('/')
def index():
    return render_template('index.html')

# Flask-SocketIO Event Handler, um den Stream an den Client zu senden
@socketio.on('connect')
def connect():
    print('Client connected')
    camera = picamera.PiCamera()
    camera.resolution = (320, 240)
    camera.framerate = 24
    for frame in gen(camera):
        socketio.emit('video', {'image': frame})

# Flask-SocketIO Event Handler, um den Stream zu beenden, wenn der Client getrennt wird
@socketio.on('disconnect')
def disconnect():
    print('Client disconnected')

if __name__ == '__main__':
    socketio.run(app)