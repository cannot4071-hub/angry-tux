# TuxFling 🐧

Drag back, aim, and fling a penguin at a pile of sad blue balls. A small open source physics game for Android, built with [Godot 4](https://godotengine.org).

> Status: early prototype. The core slingshot loop and three levels work; art is all placeholder shapes drawn in code. Contributions very welcome.

## Gameplay

- Drag the penguin back on the slingshot (mouse or touch).
- A dotted line previews your trajectory.
- Release to fling. Hard hits crack the balls; enough damage pops them.
- Pop every ball before you run out of birds (4 per level).

## Run it

1. Install [Godot 4.3+](https://godotengine.org/download) (standard build, not .NET).
2. Clone this repo and open `project.godot` in the Godot editor.
3. Press **F5**. On desktop, the mouse emulates touch.

## Build for Android

Short version (full steps in [docs/ANDROID.md](docs/ANDROID.md)):

1. Install JDK 17 and the Android SDK, then set both paths in Godot: *Editor → Editor Settings → Export → Android*.
2. *Editor → Manage Export Templates* → download templates.
3. *Project → Export → Add… → Android*, then export an APK or AAB.

Never commit your keystore or `export_presets.cfg` with credentials in it (both are git-ignored).

## Project layout

```
project.godot        Godot project config (landscape, 1280x720)
scenes/main.tscn     Single scene; everything else is built from code
scripts/main.gd      Game flow, slingshot input, levels (edit LEVELS to add more)
scripts/bird.gd      The projectile
scripts/winball.gd   The target: damage, cracks, pop
docs/ANDROID.md      Android export guide
```

## Adding a level

Open `scripts/main.gd` and append to `LEVELS`:

```gdscript
{
    "blocks": [Rect2(900, 480, 120, 160)],   # static platforms: x, y, w, h
    "balls":  [Vector2(960, 452)],           # ball centers
},
```

The ground's top edge is at y = 640, so a ball resting on it has its center at y = 612.

## Roadmap / good first issues

- [ ] Real art and sound (see CONTRIBUTING for licensing rules)
- [ ] Dynamic, breakable blocks (crates, planks) instead of static platforms
- [ ] Level select screen and saved progress
- [ ] Star ratings based on birds remaining
- [ ] Different bird types with special abilities
- [ ] Levels defined in JSON/resources so non-coders can contribute them
- [ ] GitHub Actions workflow that exports a debug APK on every release tag
- [ ] Particle effects when a ball pops
- [ ] Settings menu (sound, trajectory preview toggle)

## A note on trademarks

The balls are a generic "sad blue window" parody and the penguin is a generic drawn penguin. Please don't add Microsoft logos or assets. If you add Tux artwork, use a version whose license permits it and credit the author in `CREDITS.md`.

## License

Code is MIT, see [LICENSE](LICENSE). Art and audio contributions must be under a compatible free license (CC0, CC-BY, or MIT) and listed in `CREDITS.md`.
