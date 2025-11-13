## RebootX
**RebootX** is a powerful and safe reboot tool for Linux systems.
It gives you more control and safety than the normal `reboot` command.

## Features

- **Safe Reboot** – Unmounts all file systems before restarting.

- **Message Broadcast** – Sends a message to all logged-in users on **real TTYs or SSH sessions**. Messages do **not appear on normal GUI terminals**.

- **Delay Option** – Adds a custom delay before rebooting.

- **Force Reboot** – Forces an immediate reboot when needed.
  
- **Logging** – Records only safe and force reboot operations in `/var/log/rebootx.log`.

- Works on Kali Linux, Ubuntu, Debian, RHEL, Fedora, Arch, etc.

## Note

Before building **RebootX**, make sure the required build tools are installed on your system.

**Debian/Ubuntu/Kali/Parrot:**
```bash
sudo apt install build-essential -y
```
**Arch/BlackArch/Manjaro:**
```bash
sudo pacman -Sy base-devel --noconfirm
```
**Fedora/RHEL/CentOS:**
```bash
sudo dnf groupinstall "Development Tools" -y
```
These packages ensure that **gcc** and **make** are available for compiling and building **RebootX**

## Installation
1. **Clone the repository**
```bash
git clone https://github.com/s-r-e-e-r-a-j/RebootX.git
```
2. **Go to the RebootX directory**
```bash
cd RebootX
```
2. **Build the program**
```bash
make
```
3. **Install on your system**
```bash
make install
```
## Usage

Run as root (or with sudo):
```bash
# Normal reboot
sudo rebootx

# with options
sudo rebootx [options]
```

### Command-line options

| Option               | Description                                                                                                  |
|----------------------|--------------------------------------------------------------------------------------------------------------|
| `--safe`             | Performs a safe reboot by syncing and unmounting all file systems before rebooting. |
| `--force`            | Forces an immediate reboot without asking for confirmation. Can be combined with `--safe` or `--delay`.     |
| `--delay <seconds>` | Waits for the specified number of seconds with a visible countdown before rebooting.                          |
| `--msg "text"`      | Broadcasts a message to all logged-in users on real TTYs or SSH sessions (not shown on GUI terminals). |
| `--help`            | Displays usage information.                                                                                   |


### Examples

**Normal reboot**
```bash
sudo rebootx
```
**Safe reboot**
```bash
sudo rebootx --safe
```
**Force reboot**
```bash
sudo rebootx --force
```
**Force safe reboot**
```bash
sudo rebootx --force --safe
```
**Send message before reboot**
```bash
sudo rebootx --msg "System will reboot soon"
```
**Safe reboot with message and 10-second delay**
```bash
sudo rebootx --safe --msg "Rebooting in 10 seconds" --delay 10
```
**Force safe reboot with message and delay**
```bash
sudo rebootx --force --safe --msg "Rebooting in 5 seconds" --delay 5
```
**Show Usage**
```bash
sudo rebootx --help
```

## License
This project is licensed under the MIT License
