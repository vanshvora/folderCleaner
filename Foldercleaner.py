import customtkinter as ctk
import pybind11


from superfastcode2 import fast_tanh2

# Set color theme and appearance mode
ctk.set_default_color_theme("dark-blue")
ctk.set_appearance_mode("System")

# Function to be triggered when the button is clicked
def clean_folder():
    # Check if any entry widget is empty
    if filename.get() == "" or accessed.get() == "" or months.get() == "":
        # Show a message if any entry widget is empty
        ctk.messagebox.showinfo("Error", "Please fill all data.")
    else:
        # Show the loading window with the progress bar
        fast_tanh2(filename.get(), int(accessed.get()),int(months.get()))

# Function to hide loading window and show cleaned message
def hide_loading_window(loading_window):
    # Hide the loading window
    loading_window.withdraw()

    # Create a new window for displaying the message
    clean_window = ctk.CTk()
    clean_window.title('Folder Cleaned')
    clean_window.geometry('300x100')

    # Label to display cleaning process status
    result_label = ctk.CTkLabel(clean_window, text="Your folder is cleaned", font=("Arial", 16))
    result_label.pack(pady=15)

    # Run the clean window
    clean_window.mainloop()

# Create the root window
root = ctk.CTk()
root.title('Folder Cleaner By Error205')
root.geometry('600x400')

# Create title label
title_label = ctk.CTkLabel(root, text="Folder Cleaner By Error-205", font=("Arial", 24, "bold"))
title_label.pack(pady=15)

# Create labels and entry widgets for file name, accessed times, and months old
filename_frame = ctk.CTkFrame(root)
filename_frame.pack(pady=10)
filename_label = ctk.CTkLabel(filename_frame, text="File Name:", font=("Arial", 16))
filename_label.grid(row=0, column=0, padx=(10, 5), pady=5, sticky="w")
filename = ctk.CTkEntry(filename_frame, font=("Arial", 14), width=50)
filename.grid(row=0, column=1, padx=5, pady=5, sticky="w")

accessed_frame = ctk.CTkFrame(root)
accessed_frame.pack(pady=10)
accessed_label = ctk.CTkLabel(accessed_frame, text="Accessed Times:", font=("Arial", 16))
accessed_label.grid(row=0, column=0, padx=(10, 5), pady=5, sticky="w")
accessed = ctk.CTkEntry(accessed_frame, font=("Arial", 14), width=50)
accessed.grid(row=0, column=1, padx=5, pady=5, sticky="w")

months_frame = ctk.CTkFrame(root)
months_frame.pack(pady=10)
months_label = ctk.CTkLabel(months_frame, text="Months Old:", font=("Arial", 16))
months_label.grid(row=0, column=0, padx=(10, 5), pady=5, sticky="w")
months = ctk.CTkEntry(months_frame, font=("Arial", 14), width=50)
months.grid(row=0, column=1, padx=5, pady=5, sticky="w")

# Create a new window for the loading bar, initially hidden
loading_window = ctk.CTk()
loading_window.title('Cleaning Folder')
loading_window.geometry('300x100')
loading_window.withdraw()

# Create loading bar
loading_bar = ctk.CTkProgressBar(loading_window, width=200)
loading_bar.pack(pady=20)

# Create a button to initiate the cleaning process
clean_button = ctk.CTkButton(root, text="Clean Folder", font=("Arial", 16, "bold"), command=clean_folder)
clean_button.pack(pady=15)

# Run the GUI
root.mainloop()

