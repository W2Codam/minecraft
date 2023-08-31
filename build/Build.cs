using System;
using System.Linq;
using Nuke.Common;
using Nuke.Common.CI;
using Nuke.Common.Execution;
using Nuke.Common.IO;
using Nuke.Common.ProjectModel;
using Nuke.Common.Tooling;
using Nuke.Common.Utilities.Collections;
using static Nuke.Common.EnvironmentInfo;
using static Nuke.Common.IO.FileSystemTasks;
using static Nuke.Common.IO.PathConstruction;

class Build : NukeBuild
{
	/// Support plugins are available for:
	///   - JetBrains ReSharper        https://nuke.build/resharper
	///   - JetBrains Rider            https://nuke.build/rider
	///   - Microsoft VisualStudio     https://nuke.build/visualstudio
	///   - Microsoft VSCode           https://nuke.build/vscode

	public static int Main() => Execute<Build>(x => x.BuildCpp);

	[Parameter("Configuration to build - Default is 'Debug' (local) or 'Release' (server)")]
	readonly Configuration Configuration = IsLocalBuild ? Configuration.Debug : Configuration.Release;

	Target Clean => _ => _
			.Before(Restore)
			.Executes(() =>
			{
			});

	Target Restore => _ => _
			.Executes(() =>
			{
			});

	Target Compile => _ => _
			.DependsOn(Restore)
			.Executes(() =>
			{
				// Compile your C# code here
			});

	Target BuildCpp => _ => _
			.DependsOn(Compile) // Ensure C# code is compiled before C++ compilation
			.Executes(() =>
			{
				AbsolutePath SourceDirectory = RootDirectory / "src";

				var compilerPath = "/usr/bin/clang++";
				var sourceFiles = Globbing.GlobFiles(SourceDirectory, "**/*.cpp").Where(x => x.Name != "main.cpp").ToList();
				var headerFiles = Globbing.GlobFiles(SourceDirectory, "**/*.hpp").ToList();
				var compilerOptions = "-std=c++20 -O2 ";

				


				// Depending on the os pick the right main file (win32, linux, darwin)
				AbsolutePath mainFile;
				AbsolutePath platformDirectory = SourceDirectory / "engine" / "platform";
				if (IsWin)
					mainFile = platformDirectory / "win32" / "main.cpp";
				else if (IsLinux)
					mainFile = platformDirectory / "linux" / "main.cpp";
				else if (IsOsx)
					mainFile = platformDirectory / "darwin" / "main.cpp";
				else
					throw new Exception("Unknown OS");

				Console.WriteLine(mainFile);

				ArgumentStringHandler arguments = new();
				arguments.AppendLiteral(compilerOptions);
				arguments.AppendLiteral(string.Join(" ", sourceFiles));
				arguments.AppendLiteral($" {mainFile}");
				arguments.AppendLiteral($" -o minecraftEXE");
				arguments.AppendLiteral($" -I {SourceDirectory}");
				var process = ProcessTasks.StartProcess(compilerPath, arguments.ToStringAndClear());
				process.AssertZeroExitCode();
			});

}
