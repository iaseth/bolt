
## Bolt
A benchmarking library for C programs.

### Features
  * Ability to export to `CSV/JSON/HTML/XML`
  * Ability to generate graphs in `PNG`

### Concepts
  * Bolt has three main components: `Actions`, `Experiments` and `Milestones`.

### Actions and Experiments
  * Each `Action` and `Experiment` have an attached function 'func' which they call `n` times and report the results.
  * An `Action` records only the total time `T` taken for `n` calls to `func`.
  * An `Experiment` records the time `t` for each call to `func`.
  * Use `Action` when `n` is in millions and `t` is in nanoseconds.
  * Use `Experiment` when `n` is in thousands or less and `t` is in `milliseconds`.

### Milestones
  * `Milestones` are recorded instants when a certaint point is reached.


