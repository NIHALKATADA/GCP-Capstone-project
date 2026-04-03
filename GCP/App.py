from flask import Flask, render_template, request, flash, url_for, redirect
from flask_mysqldb import MySQL
from functools import wraps

app = Flask(__name__)
app.secret_key = 'system_secret_key'
app.config['MYSQL_HOST'] = 'localhost'
app.config['MYSQL_USER'] = 'root'
app.config['MYSQL_PASSWORD'] = 'Niuhulk@36281'
app.config['MYSQL_DB'] = 'college_events'

mysql = MySQL(app)

def check_auth(username, password):
    return username == 'admin' and password == 'password123'

def authenticate():
    return ("Unauthorized", 401, {'WWW-Authenticate': 'Basic realm="Login Required"'})

def requires_auth(f):
    @wraps(f)
    def decorated(*args, **kwargs):
        auth = request.authorization
        if not auth or not check_auth(auth.username, auth.password):
            return authenticate()
        return f(*args, **kwargs)
    return decorated

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/register', methods=['POST'])
def register():
    if request.method == 'POST':
        name = request.form['full_name']
        s_id = request.form['student_id']
        event = request.form['event_name']
        cur = mysql.connection.cursor()
        cur.execute("INSERT INTO registrations (full_name, student_id, event_name) VALUES (%s, %s, %s)", (name, s_id, event))
        mysql.connection.commit()
        cur.close()
        flash('Registration Successful!')
        return redirect(url_for('index'))

@app.route('/admin')
@requires_auth
def admin_view():
    cur = mysql.connection.cursor()
    cur.execute("SELECT * FROM registrations")
    data = cur.fetchall()
    cur.close()
    return render_template('admin.html', registrations=data)

@app.route('/delete/<int:id>')
@requires_auth
def delete_registration(id):
    cur = mysql.connection.cursor()
    cur.execute("DELETE FROM registrations WHERE id = %s", (id,))
    mysql.connection.commit()
    cur.close()
    return redirect(url_for('admin_view'))

if __name__ == '__main__':
    app.run(debug=True)