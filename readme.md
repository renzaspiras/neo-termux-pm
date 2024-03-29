# Arch-Termux

Welcome to Arch-Termux, where you can bring the power of Archlinux into your pocket! This repository provides a convenient way to install Archlinux on your Termux environment.

## Why Archlinux?

Archlinux is renowned for its simplicity, flexibility, and cutting-edge technology. It offers a lightweight and minimalist base system, allowing users to customize their environment according to their needs. With Archlinux, you have complete control over your system, enabling you to tailor it to your preferences.

## How to Install?

### Step 1: Update and Install Dependencies

Ensure that your Termux environment is up to date and has Git installed. You can do this by running the following command:

```bash
yes | pkg upgrade && yes | pkg install git
```

### Step 2: Clone the Repository

Next, clone the Arch-Termux repository to your device. Navigate to the desired directory and execute:

```bash
git clone https://github.com/renzaspiras/arch-termux.git hello
```

### Step 3: Run the Setup Script

Enter the `hello` directory and run the setup script to install Archlinux:

```bash
cd hello && bash setup.sh
```

## Quick Installation

If you prefer a more straightforward approach, you can execute the following command to perform all the steps at once:

```bash
yes | pkg upgrade && yes | pkg install git && git clone https://github.com/renzaspiras/arch-termux.git hello && cd hello && bash setup.sh
```

**Note:** Running commands without understanding them fully can pose risks. Make sure you're comfortable with the actions being taken before proceeding.

Experience the power and versatility of Archlinux right from your Termux environment with Arch-Termux!