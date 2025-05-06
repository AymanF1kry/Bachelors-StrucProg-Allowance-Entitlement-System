# Allowance Entitlement System – Structured Programming Project

![C](https://img.shields.io/badge/C-Programming-blue?logo=c)
![OnlineGDB](https://img.shields.io/badge/IDE-OnlineGDB-lightgrey?logo=codeforces)
![CLI](https://img.shields.io/badge/Interface-Command%20Line-black)
![License](https://img.shields.io/badge/License-Academic-lightgrey)

> A command-line based **Allowance Entitlement System** developed using C programming language for the **Structured Programming** course during my bachelor’s degree. Designed for applicants to check their eligibility and entitlement based on age, income, marital status, number of children, and geographic location.

---

## 🛠 Technologies Used

- **C Programming**
- **OnlineGDB.com** (Online IDE)
- **Command Line Interface (CLI)**

---

## 📁 How to Run

1. **Download** this repository as a ZIP file.
2. **Extract** the ZIP file to your preferred location.
3. **Open the `.c` file** using any C compiler of your choice.
   - If using **[OnlineGDB](https://www.onlinegdb.com/)** (recommended for simplicity):
     - Upload the `.c` file or copy the contents into the editor.
     - Click the **Run** button.
4. The program will begin running in a command-line prompt.

---

## 💡 Key Features & Logic Flow

1. **Age Check**:
   - Must be **18 years old or above** to proceed.
   - If not, a message is shown and the user can choose to **continue** or **exit**.
2. **Income Check**:
   - User must have a **monthly income of RM5000 or below**.
   - Otherwise, they are deemed ineligible with an option to **continue** or **exit**.
3. **Marital Status**:
   - If **married**, the system asks for number of children under 18.
4. **Location Prompt**:
   - User chooses whether they live in **East** or **West Malaysia**.
5. **Allowance Conditions**:
   - **Single (≥18 years)**: RM1000
   - **Married (≥18 years)**:
     - **≤4 children**: RM2500
     - **>4 children**: RM3500
   - **Additional RM500** if user lives in **East Malaysia**
6. **Result Display**:
   - Shows the **total entitlement** based on inputs.
7. **Continue Option**:
   - User can restart the process for themselves or other family members.
   - At the end, the system will **display all entered monthly incomes** in **ascending order**.

---

## 🙋‍♂️ Acknowledgements
- **Developed by Ayman Fikry bin Asmajuda as part of an academic assignment under the Structured Programming course.**
