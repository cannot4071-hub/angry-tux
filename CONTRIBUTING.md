# Contributing to TuxFling

Thanks for helping! This is a small, friendly project.

## Getting started

1. Fork and clone the repo.
2. Open `project.godot` in Godot 4.3 or newer and press F5.
3. Pick an issue (look for `good first issue`) or propose something in a new issue first if it's big.

## Guidelines

- **Keep it simple.** Prefer small, readable GDScript. Use static typing where it helps (`var x: float`, typed function signatures).
- **One change per pull request**, with a short description and, for gameplay changes, a note on how you tested it (desktop and/or Android device).
- **Style:** tabs for indentation, `snake_case` for variables and functions, `PascalCase` for classes, constants in `UPPER_SNAKE_CASE`. Godot's [GDScript style guide](https://docs.godotengine.org/en/stable/tutorials/scripting/gdscript/gdscript_styleguide.html) is the reference.
- **Levels** go in the `LEVELS` array in `scripts/main.gd`. Make sure every level is winnable, and say how many birds you needed to clear it.

## Art, sound and licensing

- Only submit assets you made yourself or that are under CC0, CC-BY, or MIT.
- Add every third-party asset to `CREDITS.md` with author, source URL and license.
- No trademarked logos or characters from other companies. The balls are a generic parody; keep them that way.
- If you add a Tux image, check the specific version's license and credit the author.

## Reporting bugs

Open an issue with: device or OS, Godot version, steps to reproduce, and what you expected vs. what happened.

## Code of conduct

Be kind and constructive. Harassment or hostility isn't tolerated; maintainers may remove comments or contributors who cross the line.
