# Koleksioni i Lojërave "Gjej Macen"

Ky depo përmban katër versione të ndryshme të lojës "Gjej Macen", secila me mekanika dhe sfida unike. Lojërat variojnë nga kërkimi i thjeshtë në dhoma deri te aventura në rrjetë me pengesa dhe kohëmatës.

## Lojërat e Përfshira

1. **Gjej Macen në Rrjetë (Grid-Based)** – Kërko për macen e fshehur në një rrjetë duke shmangur pengesat dhe duke u nxituar kundër kohës.
2. **Gjej Macen e Thjeshtë (Simple)** – Supozo në cilën dhomë (1–5) është fshehur macja, por ki kujdes nga kurthet që e rivendosin lojën.
3. **Gjej Macen me Kohë (Timed)** – Gjej macen në një nga tre dhomat brenda një kohe të kufizuar dhe me përpjekje të kufizuara.
4. **Gjej Macen Interaktive (Interactive)** – Përgjigju pyetjeve me po/jo për të kërkuar në dhoma të ndryshme në një shtëpi për macen e fshehur.

## Si të Ekzekutohen

### Kërkesat

- Kompajler C++ (g++, clang, ose MSVC)
- Luajtës mediesh që mund të hapë skedarë MP4 (për videot e fitores)
- Në Windows: Luajtësi i parazgjedhur ose VLC
- Në Linux/Mac: VLC i rekomanduar

### Udhëzime për Kompilim

Kompilo secilën lojë veçmas duke përdorur kompajlerin tënd të preferuar C++. Për shembull:

```bash
g++ grid_cat_finder.cpp -o grid_cat_finder -std=c++11 -pthread
g++ simple_cat_finder.cpp -o simple_cat_finder
g++ timed_cat_finder.cpp -o timed_cat_finder -std=c++11 -pthread
g++ interactive_cat_finder.cpp -o interactive_cat_finder
```

### Ekzekutimi i Lojërave

Pas kompilimit, ekzekuto fajllat e prodhuar:

```bash
./grid_cat_finder
./simple_cat_finder
./timed_cat_finder
./interactive_cat_finder
```

**Shënim:** Që videot e fitores me mace të funksionojnë, duhet:

1. Të krijoni një dosje `media` në të njëjtin folder me ekzekutuesit
2. Të vendosni skedarët përkatës të videove në dosjen `media`:
- `kittens_video.mp4` për lojën me rrjetë
- `kittens2_video.mp4` për lojën e thjeshtë
- `kittens3_video.mp4` për lojën me kohë
- `kittens4_video.mp4` për lojën interaktive

## Si të Kontribuoni

Kontributet janë të mirëseardhura për të përmirësuar këto lojëra! Ja si mund të ndihmoni:

1. **Fork**-oni depo-në
2. Krijoni një **degezim të ri (branch)** për funksionalitetin apo rregullimin tuaj
3. Bëni ndryshimet
4. Dërgoni një **pull request**

### Fusha për Kontribut

- Shtoni mekanika ose variante të reja lojërash
- Përmirësoni ndërfaqen e përdoruesit
- Shtoni më shumë ndihma ose nivele vështirësie
- Zbatoni validim më të mirë të inputit
- Përmirësoni përputhshmërinë në platforma të ndryshme
- Krijoni video të reja fitoreje ose grafikë shtesë

## Përshkrimet e Lojërave

### 1. Gjej Macen në Rrjetë (Grid-Based)

- Kërkoni për macen e fshehur në një rrjetë të gjeneruar dinamikisht
- Shmangni pengesat e shënuara me `#`
- Merrni ndihma pas 3 përpjekjeve të pasuksesshme
- Gara kundër një kohëmatësi 30-sekondësh
- Shfaqje në stil ASCII-art të rrjetës

### 2. Gjej Macen e Thjeshtë (Simple)

- Supozoni në cilën nga 5 dhomat fshihet macja
- Ki kujdes nga kurthet që e rivendosin lojën
- Ndërfaqe e thjeshtë me dhoma
- Luaj video me mace kur fiton

### 3. Gjej Macen me Kohë (Timed)

- Zgjidh midis dhomës së Majtë, të Mesme, ose të Djathtë
- Kufizohet në 5 përpjekje
- Afat kohor prej 30 sekondash
- Shfaqje vizuale e dhomave me mekanikë zbulimi

### 4. Gjej Macen Interaktive (Interactive)

- Përgjigju pyetjeve me Po/Jo për të kërkuar në dhoma
- Kufizohet në 3 përpjekje
- Dhomat përfshijnë: Dhoma e Ndenjes, Kuzhina, Banjo, Dhoma e Gjumit dhe Papafingo
- Ndërfaqe e thjeshtë me pyetje

## Licenca

Ky projekt është open-source dhe i disponueshëm për përdorim dhe modifikim të lirë.


