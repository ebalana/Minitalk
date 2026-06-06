# Minitalk
> 42 school project developed by Ernest Balañá

## Description
`minitalk` is a small data transmission system designed to facilitate communication between a client and a server process using UNIX signals. The purpose of the project is to understand inter-process communication (IPC) and bitwise manipulation in a Unix environment.

## Features
- **Signal-Based IPC:** Communication is handled exclusively through `SIGUSR1` and `SIGUSR2` signals.
- **Bitwise Protocol:** Characters are broken down into bits by the client, transmitted via signals, and reconstructed by the server.
- **Fast and Reliable:** Optimized to ensure zero data loss or synchronization issues during transmission.
- **Personal Study Notes:** [My Notion Notes](https://app.notion.com/p/vienatrip/MiniTalk-19e00fe299ed80d88873ea770d605527?source=copy_link)

## 🛠️ Installation
```bash
git clone https://github.com/ebalana/Minitalk.git
cd Minitalk
make
