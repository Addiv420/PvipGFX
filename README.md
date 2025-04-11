# PvipGFX

PvipGFX is a simple Pong game built using the **VipGFX library** by [key-real on SourceForge](https://sourceforge.net/projects/vipgfx/).

## Features

- **Classic Gameplay Mechanics**
  - Two-player controls (W/S and ↑/↓ keys)
  - Ball physics with wall/paddle collision
  - Score tracking system
- **Visual Elements**
  - Clean retro-style UI
  - Colored paddles and ball
  - Center court divider
- **Technical Implementation**
  - Frame-based animation system
  - Pixel-perfect collision detection
  - Responsive input handling

## Installation

### Dependencies
- VIPGFX graphics library
- C++17 compatible compiler

```bash
# Download
git clone https://github.com/Addiv420/PvipGFX.git
cd PvipGFX/src

# Starting Pong
export LD_LIBRARY_PATH=:.
./pong

# Build Pong
src/compiler.sh
```

---

If you have any questions or would like to contribute to this project, feel free to open an issue on GitHub!
