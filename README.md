# 🧮 Pi Finder C++

**Pi Finder C++** demonstriert die Verwendung von Mehrpräzisionsbibliotheken (MPFR/GMP) und schnellen Suchalgorithmen (KMP), um Dezimalstellen von π zu berechnen und darin nach Zahlenfolgen — z. B. einem Geburtsdatum im Format TTMMJJJJ — zu suchen.

Kurz: das Programm berechnet viele Dezimalstellen von π, sucht nach einer eingegebenen Ziffernfolge und gibt Position plus Kontext aus.

---

## 🚀 Funktionen
- Hochpräzise Berechnung von π mit MPFR/GMP  
- Schnelle Suche mittels Knuth–Morris–Pratt (KMP)  
- Ergebnisanzeige mit Position und Kontext (z. B. ...1234 [5678] 9012...)  
- Interaktive Konsolenoberfläche  
- Plattformübergreifend (Linux / macOS / Windows)  
- CI-Build via GitHub Actions

---

## ⚙️ Voraussetzungen
- CMake, ein C++-Compiler (g++, clang++)  
- Entwicklungs-Bibliotheken: libmpfr-dev, libgmp-dev (Linux)  
- Optional: vcpkg (Windows)

---

## 🔧 Lokale Kompilierung

### Linux / macOS (Ubuntu Beispiel)
```bash
sudo apt-get update
sudo apt-get install -y cmake build-essential libmpfr-dev libgmp-dev
cmake -B build -S .
cmake --build build --config Release
./build/pi_finder
```

### Windows (vcpkg)
```powershell
vcpkg install mpfr gmp
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="C:\vcpkg\scripts\buildsystems\vcpkg.cmake"
cmake --build build --config Release
.\build\Release\pi_finder.exe
```

---

## 🧩 Beispiel (Programmstart)
```
$ ./build/pi_finder
👋 Hallo!
π (Pi) hat unendliche und nicht periodische Dezimalstellen...
Wähle: 1) Ziffernfolge  2) Geburtsdatum
→ Gib dein Datum im Format 23041992 ein

✅ Die Geburtsdatum-Sequenz "23041992" erscheint an Position 1 234 der Dezimalstellen von π (nach dem 3.).
Kontext:
...5678 [23041992] 9012...
```

Hinweis: Geburtsdatum bitte ohne Trennzeichen im Format TTMMJJJJ (z. B. 23041992).

---

## 🧠 Lehrziele
- Einsatz von Mehrpräzisionsarithmetik (MPFR/GMP)  
- Implementierung und Nutzung effizienter Suchalgorithmen (KMP)  
- Demonstration von Build- und Test-Automatisierung (CI)

---

## 🔑 Lizenz
MIT License — siehe LICENSE-Datei im Repository.

Viel Erfolg beim Ausprobieren und Erweitern!