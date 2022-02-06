#ifndef SEMVER_TEST_DATASET_HPP
#define SEMVER_TEST_DATASET_HPP

namespace semver::dataset {
inline constexpr std::array<std::pair<version_view, std::string_view>, 32> valid_versions = {{
  {version_view{0, 0, 4, {}, {}}, "0.0.4"},
  {version_view{1, 2, 3, {}, {}}, "1.2.3"},
  {version_view{10, 20, 30, {}, {}}, "10.20.30"},
  {version_view{1, 1, 2, "prerelease", "meta"}, "1.1.2-prerelease+meta"},
  {version_view{1, 1, 2, "", "meta" }, "1.1.2+meta"},
  {version_view{1, 1, 2, "", "meta-valid" }, "1.1.2+meta-valid"},
  {version_view{1, 0, 0, "alpha", {}}, "1.0.0-alpha"},
  {version_view{1, 0, 0, "beta", {}}, "1.0.0-beta"},
  {version_view{1, 0, 0, "alpha.beta", {}}, "1.0.0-alpha.beta"},
  {version_view{1, 0, 0, "alpha.beta.1", {}}, "1.0.0-alpha.beta.1"},
  {version_view{1, 0, 0, "alpha.1", {}}, "1.0.0-alpha.1"},
  {version_view{1, 0, 0, "alpha0.valid", {}}, "1.0.0-alpha0.valid"},
  {version_view{1, 0, 0, "alpha.0valid", {}}, "1.0.0-alpha.0valid"},
  {version_view{1, 0, 0, "alpha-a.b-c-somethinglong", "build.1-aef.1-its-okay"}, "1.0.0-alpha-a.b-c-somethinglong+build.1-aef.1-its-okay"},
  {version_view{1, 2, 3, "rc.4", {}}, "1.2.3-rc.4"},
  {version_view{1, 0, 0, "rc.1", "build.1"}, "1.0.0-rc.1+build.1"},
  {version_view{2, 0, 0, "rc.1", "build.123"}, "2.0.0-rc.1+build.123"},
  {version_view{1, 2, 3, "beta", {}}, "1.2.3-beta"},
  {version_view{10, 2, 3, "DEV-SNAPSHOT", {}}, "10.2.3-DEV-SNAPSHOT"},
  {version_view{1, 2, 3, "SNAPSHOT-123", {}}, "1.2.3-SNAPSHOT-123"},
  {version_view{1, 0, 0, {}, {}}, "1.0.0"},
  {version_view{2, 0, 0, {}, {}}, "2.0.0"},
  {version_view{1, 1, 7, {}, {}}, "1.1.7"},
  {version_view{2, 0, 0, "", "build.1848"}, "2.0.0+build.1848"},
  {version_view{2, 0, 1, "alpha.1227", {}}, "2.0.1-alpha.1227"},
  {version_view{1, 0, 0, "alpha", "beta"}, "1.0.0-alpha+beta"},
  {version_view{1, 2, 3, "---RC-SNAPSHOT.12.9.1--.12", "788"}, "1.2.3----RC-SNAPSHOT.12.9.1--.12+788"},
  {version_view{1, 2, 3, "---R-S.12.9.1--.12", "meta"}, "1.2.3----R-S.12.9.1--.12+meta"},
  {version_view{1, 2, 3, "---RC-SNAPSHOT.12.9.1--.12", {}}, "1.2.3----RC-SNAPSHOT.12.9.1--.12"},
  {version_view{1, 0, 0, "", "0.build.1-rc.10000aaa-kk-0.1"}, "1.0.0+0.build.1-rc.10000aaa-kk-0.1"},
  {version_view{999999999, 999999999, 999999999, {}, {}}, "999999999.999999999.999999999"},
  {version_view{1, 0, 0, "0A.is.legal", {}}, "1.0.0-0A.is.legal"}
}};

inline constexpr std::array<std::pair<std::string_view, std::ptrdiff_t>, 45> invalid_versions = {{
  {"1", 1},
  {"1.2", 3},
  {"1.2.3-0123", 6},
  {"1.2.3-0123.0123", 6},
  {"1.0.0-", 6},
  {"1.0.0+", 6},
  {"1.0.0-.", 6},
  {"1.0.0+.", 6},
  {"1.0.0-.+.", 6},
  {"1.1.2+.123", 6},
  {"+invalid", 0},
  {"-invalid", 0},
  {"-invalid+invalid", 0},
  {"-invalid.01", 0},
  {"alpha", 0},
  {"alpha.beta", 0},
  {"alpha.beta.1", 0},
  {"alpha.1", 0},
  {"alpha+beta", 0},
  {"alpha_beta", 0},
  {"alpha.", 0},
  {"alpha..", 0},
  {"beta", 0},
  {"1.0.0-alpha_beta", 11},
  {"-alpha.", 0},
  {"1.0.0-alpha..", 12},
  {"1.0.0-alpha..1", 12},
  {"1.0.0-alpha...1", 12},
  {"1.0.0-alpha....1", 12},
  {"1.0.0-alpha.....1", 12},
  {"1.0.0-alpha......1", 12},
  {"1.0.0-alpha.......1", 12},
  {"01.1.1", 0},
  {"1.01.1", 2},
  {"1.1.01", 4},
  {"1.2.", 4},
  {"1.2.3.DEV", 5},
  {"1.2-SNAPSHOT", 3},
  {"1.2.31.2.3----RC-SNAPSHOT.12.09.1--..12+788", 6},
  {"1.2-RC-SNAPSHOT", 3},
  {"-1.0.3-gamma+b7718", 0},
  {"+justmeta", 0},
  {"9.8.7+meta+meta", 10},
  {"9.8.7-whatever+meta+meta", 19},
  {"99999999999999999999999.999999999999999999.99999999999999999----RC-SNAPSHOT.12.09.1--------------------------------..12", 0}
}};
}

#endif //SEMVER_TEST_DATASET_HPP