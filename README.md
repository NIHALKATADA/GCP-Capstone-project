# College Event Registration System (GCP Capstone)

A functional web application prototype designed for **Karnavati University**. This system automates the student registration process for campus events and provides a secure, administrative dashboard for data management.

## 🚀 Key Features
- **Student Registration Portal**: User-friendly form styled to match the official KU interface.
- **Admin Dashboard**: A secure area to manage, search, and sort event data.
- **Full CRUD Support**: Capabilities to Create (Register), Read (Dashboard), and Delete records.
- **Real-time Filtering**: Integrated search and sort functionality using DataTables.
- **Secure Authentication**: Basic HTTP Authentication for administrative access.

## 🛠️ Technology Stack
- **Backend**: Python 3.13 (Flask Framework)
- **Database**: MySQL (local development via XAMPP/MySQL Workbench)
- **Frontend**: HTML5, CSS3 (Grid & Flexbox), JavaScript (jQuery & DataTables)
- **Version Control**: Git & GitHub

## 📂 Project Structure
- `App.py`: Main Flask application containing routing and database logic.
- `templates/`: Folder containing the frontend HTML components.
    - `index.html`: The public-facing registration form.
    - `admin.html`: The administrative table with search/sort features.
    - `view_event.html`: Individual record detail view.
- `requirements.txt`: List of Python dependencies for environment setup.

## ⚙️ Setup Instructions
1. **Clone the repository**:
   ```bash
   git clone [https://github.com/NIHALKATADA/GCP-Capstone-project.git](https://github.com/NIHALKATADA/GCP-Capstone-project.git)
