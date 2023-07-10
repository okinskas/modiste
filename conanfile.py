from conan import ConanFile


class Recipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps", "VirtualRunEnv"

    def layout(self):
        self.folders.generators = "conan"

    def requirements(self):
        self.requires("fmt/10.0.0")
        self.requires("protobuf/3.21.9")
        self.requires("boost/1.82.0")
        # self.requires("Outcome/master@ned14/stable")

    def build_requirements(self):
        pass
