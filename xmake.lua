add_rules("mode.debug", "mode.release")

add_requires("dpp")

target("test_xmake")
    set_kind("binary")
    add_includedirs("include")
    add_files("src/*.cpp")
    add_headerfiles("include/*.hpp")
    add_languages("c++20")

    add_packages("dpp")