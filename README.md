# DWM — DOTS

<h2 align="center"> ━━━━━━  ❖  ━━━━━━ </h2>

<!-- BADGES -->
<div align="center">
    <p></p>
    <a href="https://github.com/CarlosMolinesPastor/dwm-dots/stargazers">
        <img src="https://img.shields.io/github/stars/CarlosMolinesPastor/dwm-dots?colorA=1e1e28&colorB=%23101415&style=for-the-badge">
    </a>
    <a href="https://github.com/CarlosMolinesPastor/dwm-dots/network/members/">
        <img src="https://img.shields.io/github/forks/CarlosMolinesPastor/dwm-dots?colorA=1e1e28&colorB=%23101415&style=for-the-badge">
    </a>
    <img src="https://img.shields.io/github/repo-size/CarlosMolinesPastor/dwm-dots?colorA=1e1e28&colorB=%23101415&style=for-the-badge">
    <img src="https://badges.pufler.dev/visits/CarlosMolinesPastor/dwm-dots?style=for-the-badge&colorA=1e1e28&colorB=white&labelColor=101415">
</div>

<p/>

---

## 🧩 Componentes del entorno

| Componente | Descripción |
|---|---|
| **Window Manager** | [dwm](https://dwm.suckless.org/) — mosaico dinámico, ligero y minimalista. |
| **Terminal** | [st](https://st.suckless.org/) — simple, rápido y con soporte para imágenes. |
| **Shell** | [Zsh](https://www.zsh.org/) + [Starship](https://github.com/starship/starship) — prompt multiplataforma. |
| **Barra** | [dwm-bar](https://github.com/siduck/chadwm) — sencilla, sin lujos. |
| **Compositor** | [Picom (jonaburg-fix)](https://github.com/Arian8j2/picom-jonaburg-fix) — esquinas redondeadas y blur. |
| **Notificaciones** | [Dunst](https://github.com/dunst-project/dunst) — minimalista. |
| **Lanzador** | [Rofi](https://github.com/davatorium/rofi) — rápido y customizable. |
| **Gestor de archivos** | [Thunar](https://docs.xfce.org/xfce/thunar/start) + [Ranger](https://github.com/ranger/ranger) — GUI y TUI. |
| **Editor** | [Neovim](https://github.com/vlagh3/NvChad) — IDE ligero y hermoso. |
| **Redes** | [Gazelle TUI](https://github.com/Zeus-Deus/gazelle-tui) — gestor de WiFi desde la terminal. |

---

## 🖼️ Este es mi desktop actual

<img src='.misc/vid.gif'>

---

## 🌸 Setup — Paso a paso

> ⚠️ **Disclaimer:** Esta configuración está pensada para **Arch Linux** (y derivados: Artix, EndeavourOS, Manjaro). Si usas otra distribución, tendrás que adaptar las dependencias. **No recomiendo copiar y pegar al pie de la letra**, sino inspirarse y entender cada paso. Como dicen en la comunidad Linux: [R.T.F.M](https://en.wikipedia.org/wiki/RTFM).

### Instalación (¡Mucho cuidado con esto!)

<details>
<summary><b>Automática (recomendada)</b></summary>

```sh
cd ~/Downloads/
git clone https://github.com/CarlosMolinesPastor/install_dwm.git
cd install_dwm
chmod +x install.sh
./install.sh
```
</details><details> <summary><b>Manual (paso a paso)</b></summary>

### 1. Instalar Paru como AUR Helper

```sh
echo "### Installing paru as AUR Helper"
mkdir -p $HOME/Downloads/_cloned-repos
cd $HOME/Downloads/_cloned-repos
git clone https://aur.archlinux.org/paru.git
cd paru
makepkg -si
```

### 2. Instalar los paquetes requeridos

```sh
echo "### Installing Required Packages"
paru -S dunst ffmpeg ffmpegthumbnailer tumbler neovim viewnior mpv rofi rsync scrot \
picom-jonaburg-fix pavucontrol ranger noto-fonts xwallpaper imlib2 fzf exa bat      \
gvfs file-roller xclip ueberzug pacman-contrib cava libxft-bgra rofi-emoji starship \
gazelle-tui networkmanager network-manager-applet                                   \
pipewire pipewire-alsa pipewire-pulse  # Reemplazando pulseaudio                    \
thunar thunar-volman thunar-archive-plugin
```

### 3. Instalar plugins de Oh-My-Zsh

```sh
echo "### Installing Oh-My-Zsh Plugins"
git clone --depth 1 https://github.com/zdharma-continuum/fast-syntax-highlighting.git $HOME/.oh-my-zsh/custom/plugins/fast-syntax-highlighting
git clone --depth 1 https://github.com/zsh-users/zsh-autosuggestions.git $HOME/.oh-my-zsh/custom/plugins/zsh-autosuggestions
git clone --depth 1 https://github.com/zsh-users/zsh-completions.git $HOME/.oh-my-zsh/custom/plugins/zsh-completions
```

### 4. Clonar y copiar los Dotfiles

```sh
git clone https://github.com/CarlosMolinesPastor/dwm-dots $HOME/dwm-dots/
cd $HOME/dwm-dots/
rsync -avxHAXP --exclude '.git*' .* ~/
```

### 5. Instalar las fuentes Nerd

```sh
mkdir -p $HOME/Downloads/nerdfonts/
cd $HOME/Downloads/

wget https://github.com/ryanoasis/nerd-fonts/releases/download/2.2.0-RC/CascadiaCode.zip
wget https://github.com/ryanoasis/nerd-fonts/releases/download/2.2.0-RC/Iosevka.zip
wget https://github.com/ryanoasis/nerd-fonts/releases/download/2.2.0-RC/JetBrainsMono.zip
wget https://github.com/ryanoasis/nerd-fonts/releases/download/2.2.0-RC/Noto.zip

unzip '*.zip' -d $HOME/Downloads/nerdfonts/
rm -rf *.zip

sudo cp -R $HOME/Downloads/nerdfonts/ /usr/share/fonts/
```

### 6. Regenerar la caché de fuentes

```sh
fc-cache -rv
```

### 7. Compilar e instalar DWM

```sh
cd $HOME/dwm-dots/lnxdwm/
sudo make install
```

### 8. Compilar e instalar ST

```sh
cd $HOME/dwm-dots/st/
sudo make install
```
</details> 

## ⌨️ Atajos de dwm (MODKEY = Super/Windows)

| Atajo | Acción |
|---|---|
| `Super + t` | Abrir terminal (**st**) |
| `Super + e` | Abrir **Thunar** |
| `Super + b` | Abrir **Firefox** |
| `Super + c` | Rofi drun |
| `Super + a` / `Super + r` | Menú de apps (rofi) |
| `Super + o` | Selector de emoji |
| `Super + n` | **Gazelle TUI** (redes WiFi) |
| `Super + x` | Powermenu |
| `Super + v` | Control de volumen |
| `Super + p` | Script de monitores |
| `Super + w` | Mostrar/ocultar barra |
| `Super + q` | Cerrar ventana |
| `Super + m` | Pantalla completa |
| `Super + s` | Layout spiral |
| `Super + Shift + m` | Layout tile |
| `Super + Shift + f` | Layout monocle |
| `Super + F2` / `F3` | Restaurar / ocultar ventana |
| `Super + F4` / `F5` | Subir / bajar volumen |
| `Super + 1..5` | Ir a etiqueta 1-5 |
| `Super + Shift + 1..5` | Mover ventana a etiqueta |
| `Super + Ctrl + q` | Salir de dwm |
| `Super + Shift + r` | Reiniciar dwm |

> 📖 Para la lista completa, consulta el `config.h` en `~/dwm-dots/lnxdwm/`.

---

## 📦 Dependencias instaladas

| Categoría | Paquetes |
|---|---|
| **Sistema** | `python`, `ffmpeg`, `pipewire`, `pipewire-alsa`, `pipewire-pulse`, `pacman-contrib` |
| **Archivos** | `thunar`, `thunar-archive-plugin`, `thunar-volman`, `ffmpegthumbnailer`, `tumbler`, `file-roller`, `gvfs`, `gvfs-mtp` |
| **Multimedia** | `alsa-utils`, `viewnior`, `mpv`, `pavucontrol`, `cava` |
| **Utilidades** | `htop`, `lxappearance`, `picom-jonaburg-fix`, `rofi`, `rsync`, `dunst`, `ranger`, `neovim`, `exa`, `bat`, `fzf`, `xclip`, `xdotool`, `scrot`, `ueberzug` |
| **Fuentes** | `noto-fonts`, `noto-fonts-emoji`, `noto-fonts-cjk`, `libxft-bgra` |
| **Xorg** | `xwallpaper`, `xcolor`, `xorg-xsetroot`, `xdotool` |
| **Redes** | `networkmanager`, `network-manager-applet`, `gazelle-tui` |
| **Shell** | `zsh`, `python-pip`, `starship` |
| **Rofi** | `rofi-emoji` |
| **Vídeo** | `ytfzf` |
| **Varios** | `xdg-user-dirs`, `imlib2` |

---

## 🎨 Personalización

- **dwm:** Edita `~/dwm-dots/lnxdwm/config.h` y recompila con `sudo make clean install`.
- **st:** Edita `~/dwm-dots/st/config.h` y recompila.
- **Autostart:** Modifica `~/.dwm/autostart.sh`.
- **Barra:** Personaliza `~/.dwm/bar/bar.sh`.
- **Colores:** Usa `wal` (pywal) para cambiar el esquema de colores.

---

## 🧹 Post-instalación

1. **Reinicia Xorg** (cierra sesión y vuelve a entrar) para que dwm y st se inicien correctamente.
2. **Activa NetworkManager** si no está activo:
   ```bash
   sudo systemctl enable --now NetworkManager
   ```
3. **Verifica que nm-applet se inicia — El script de autostart de dwm ya lo lanza.
4. **Disfruta de tu rice 🎉

## 🙏 Créditos

- **Script original:** [linuxmobile](https://github.com/linuxmobile) — [dwm-dots](https://github.com/linuxmobile/dwm-dots)
- **Dotfiles base:** [linuxmobile/dwm-dots](https://github.com/linuxmobile/dwm-dots)
- **dwm:** [suckless.org](https://dwm.suckless.org/)
- **st:** [suckless.org](https://st.suckless.org/)
- **Gazelle TUI:** [Zeus-Deus/gazelle-tui](https://github.com/Zeus-Deus/gazelle-tui)
- **Nerd Fonts:** [ryanoasis/nerd-fonts](https://github.com/ryanoasis/nerd-fonts)
- **Oh-My-Zsh:** [ohmyzsh/ohmyzsh](https://github.com/ohmyzsh/ohmyzsh)

**©** A todos los artistas que crearon los iconos, ilustraciones y wallpapers.
**©** A cada uno que ha creado y mantiene los proyectos mencionados.

© [Owl4ce](https://github.com/owl4ce)
© [Ilham25](https://github.com/ilham25)
© [Siduck](https://github.com/siduck)
© [NvChad](https://github.com/NvChad)
© [linuxmobile](https://github.com/linuxmobile)

---

## 📄 Licencia

Este proyecto se distribuye bajo la licencia **MIT**. Consulta el archivo [LICENSE](LICENSE) para más detalles.

---

*Hecho con ❤️ para la comunidad de dwm.*
