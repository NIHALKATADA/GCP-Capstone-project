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
    cur = mysql.connection.cursor()
    cur.execute("SELECT * FROM registrations ORDER BY id DESC")
    data = cur.fetchall()
    total_reg = len(data)
    cur.close()
    return render_template('index.html', registrations=data, total_count=total_reg)

@app.route('/events')
def events_page():
    available_events = [
        {"name": "Tech Fest 2026", "desc": "Annual flagship technical festival featuring robotics.", "date": "March 15"},
        {"name": "Cloud Computing Workshop", "desc": "Hands-on session on Google Cloud Foundations.", "date": "March 20"},
        {"name": "KU Hackathon 1.0", "desc": "24-hour building challenge.", "date": "April 05"},
        {"name": "Cultural Night", "desc": "Celebration of music and arts.", "date": "April 12"},
        {"name": "Sports Carnival", "desc": "Inter-departmental sports meet.", "date": "April 20"}
    ]
    return render_template('events.html', events=available_events)

@app.route('/register', methods=['POST'])
def register():
    if request.method == 'POST':
        cur = mysql.connection.cursor()
        cur.execute("INSERT INTO registrations (full_name, student_id, email, department, phone, event_name) VALUES (%s, %s, %s, %s, %s, %s)", 
                    (request.form['full_name'], request.form['student_id'], request.form['email'], request.form['department'], request.form['phone'], request.form['event_name']))
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

@app.route('/delete/<int:reg_id>')
@requires_auth
def delete_registration(reg_id):
    cur = mysql.connection.cursor()
    cur.execute("DELETE FROM registrations WHERE id = %s", (reg_id,))
    mysql.connection.commit()
    cur.close()
    return redirect(url_for('admin_view'))

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=True)