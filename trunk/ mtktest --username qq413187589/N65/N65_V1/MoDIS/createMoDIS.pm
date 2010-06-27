package createMoDIS;
use strict;
use DirHandle;
use File::Basename;

#######################################################################################################################
#######################################################################################################################
#######################################################################################################################
sub create_header
{
	my $lib = shift;
	my $result = <<__STRING__
# Microsoft Developer Studio Project File - Name="$lib" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=$lib - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "$lib.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "$lib.mak" CFG="$lib - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "$lib - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "$lib - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

__STRING__
;
	return $result;
}
#######################################################################################################################
#######################################################################################################################
#######################################################################################################################
sub create_compile_option
{
	my $lib = shift;
	my $compile_option = shift;
	my $include_path = shift;

	my $result;

	my $option_set = "";
	#foreach my $option (split("\n",$compile_option . $include_path ))
	#{
	#	$option_set .= "# ADD CPP $option\n";
	#}
	foreach my $option (split("\n",$compile_option . $include_path ))
	{
		$option_set .= "$option\n";
	}
	
	{
		open H,">$lib/$lib.ini";
		print H $option_set;
		close H;
	}

	my $lib1 = "@\"" . $lib . ".ini\"";
	$result = <<__STRING__
!IF  "\$(CFG)" == "$lib - Win32 Release"
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
__STRING__
;
  if(lc($lib) eq "iperf") {
     $result .= <<__STRING__
# ADD BASE CPP /nologo /W3 /Gm /GX /Od /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /W2 /Od /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" 
__STRING__
;
   } else {
     $result .= <<__STRING__
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /W2 /Od /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" 
__STRING__
;
   }
     $result .= <<__STRING__
# ADD CPP $lib1
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ELSEIF  "\$(CFG)" == "$lib - Win32 Debug"
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
__STRING__
;
  if (lc($lib) eq "iperf") {
     $result .= <<__STRING__
# ADD BASE CPP /nologo /W3 /Gm /GX /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /W2 /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" 
__STRING__
;
   } else {
     $result .= <<__STRING__
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /W2 /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" 
__STRING__
;
   }
     $result .= <<__STRING__
# ADD CPP $lib1
# ADD CPP /FD /GZ /c
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
!ENDIF
__STRING__
;
	return $result;
}
#######################################################################################################################
#######################################################################################################################
#######################################################################################################################
my %file_list_table;
my %added_file_list_table;
my $added_file_list_table_cnt;

sub output_source_file
{
	my $lib = shift;
	my $fullpath = shift;
	my $node = shift;
	my $WIN32_COMPILE_OPTION = shift;
	my $result = "";
	$result .= "# Begin Source File \n";
	$result .= "SOURCE=$fullpath\\$node\n";
	if(defined($$WIN32_COMPILE_OPTION{lc("$fullpath\\$node")}))
	{
		$result .= "# ADD CPP " . $$WIN32_COMPILE_OPTION{lc("$fullpath\\$node")} . "\n";
	}
	elsif(defined($$WIN32_COMPILE_OPTION{lc($node)}))
	{
		$result .= "# ADD CPP " . $$WIN32_COMPILE_OPTION{lc($node)} . "\n";
	}

	if(lc($node)=~ /\.asm$/) # Assembler file
	{
		$result .= <<__STRING__
!IF  "\$(CFG)" == "$lib - Win32 Release"
# Begin Custom Build
"\$(OutDir)\\\$(InputName).obj" : \$(SOURCE) "\$(INTDIR)" "\$(OUTDIR)"
	"\$(WkspDir)\\ml.exe" /nologo /c /coff /Zi /FR -Fo\$(OutDir)\\\$(InputName).obj \$(InputDir)\\\$(InputName).asm
# End Custom Build
!ELSEIF  "\$(CFG)" == "$lib - Win32 Debug"
# Begin Custom Build
"\$(OutDir)\\\$(InputName).obj" : \$(SOURCE) "\$(INTDIR)" "\$(OUTDIR)"
	"\$(WkspDir)\\ml.exe" /nologo /c /coff /Zi /FR -Fo\$(OutDir)\\\$(InputName).obj \$(InputDir)\\\$(InputName).asm
# End Custom Build
!ENDIF
__STRING__
	}
	$result .= "# End Source File \n";
	return $result;
}
sub create_group_source_tree
{
	my $level = shift;
	my $lib = shift;
	my $fullpath = shift;
	my $path = shift;
	my $WIN32_COMPILE_OPTION = shift;


	my $dir = new DirHandle();
	my $result = "";

	$level++;

	$result .= "# Begin Group \"$path\"\n" if($level>1);
	opendir $dir,"$lib/$fullpath";
	foreach my $node (sort readdir($dir))
	{
		next if($node eq '.');
		next if($node eq '..');
		if(-d "$lib/$fullpath/$node")
		{
			my $file_counter = $added_file_list_table_cnt;
			my $content = create_group_source_tree($level,$lib,"$fullpath\\$node",$node,$WIN32_COMPILE_OPTION);
			$result .= $content if($file_counter < $added_file_list_table_cnt);
		}
		else
		{
			next if(($file_list_table{lc("$fullpath\\$node")} != 1));
			next if($node =~ /\.c$/ && !defined($file_list_table{lc("$fullpath\\$node")}));
			next if($node =~ /\.cpp$/ && !defined($file_list_table{lc("$fullpath\\$node")}));
			next if(defined($added_file_list_table{lc("$fullpath\\$node")}));

			if($node =~ /\.h$/i
			|| $node =~ /\.hpp$/i
			|| $node =~ /\.c$/i
			|| $node =~ /\.cpp$/i
			|| $node =~ /\.asm$/i
			|| $node =~ /\.txt$/i
			|| $node =~ /\.bat$/i)
			{
				$added_file_list_table{lc("$fullpath\\$node")} = 1;
				$result .= output_source_file($lib, $fullpath,$node,$WIN32_COMPILE_OPTION);
				$added_file_list_table_cnt ++;
			}
		}
	}
	closedir $dir;
	$result .= "# End Group \"$path\"\n" if($level>1);

	$level--;
	return $result;
}
sub create_file_list
{
	my $lib = shift;
	my $file_list = lc(shift);
	my $WIN32_COMPILE_OPTION = shift;

	my $list_set = "";
	my @unsort;

	undef %file_list_table;
	undef %added_file_list_table;
	$added_file_list_table_cnt=0;

	foreach my $file (split("\n",$file_list))
	{
		$file_list_table{lc($file)} = 1;
	}

	foreach my $file (sort keys %file_list_table)
	{
		(! -e "$lib/$file") && warn "$lib => $file does NOT exist!\n";
		next if(defined($added_file_list_table{lc($file)}));

		if($file =~ /^(.*?\\$lib)\\/i)
		{
			my $root = $1;
			$list_set .= create_group_source_tree(0,$lib,$root,$lib,$WIN32_COMPILE_OPTION);
		}
		else
		{
			push @unsort,$file;
		}
	}

	foreach my $file (sort @unsort)
	{
		$list_set .= output_source_file($lib, dirname($file),basename($file),$WIN32_COMPILE_OPTION);
	}
	my $result;
	$result = <<__STRING__
# Begin Target
# Name "$lib - Win32 Release"
# Name "$lib - Win32 Debug"
$list_set
__STRING__
;
	return $result;
}
#######################################################################################################################
#######################################################################################################################
#######################################################################################################################
sub create_foot
{
	return <<__STRING__
# End Target
# End Project
__STRING__
;
}
#######################################################################################################################
#######################################################################################################################
#######################################################################################################################
sub create_lib_project
{
	my $lib = shift;
	my $dep_filename = shift;
	my $compile_option = shift;
	my $include_path = shift;
	my $file_list = shift;
	my $WIN32_COMPILE_OPTION = shift;

	my $result = '';
	print ".";
	$result .= create_header($lib);
	print ".";
	$result .= create_compile_option($lib,$compile_option,$include_path);
	print ".";
	$result .= create_file_list($lib,$file_list,$WIN32_COMPILE_OPTION);
	print ".";
	$result .= create_foot($lib);
	print ".";

	#print "Write $dep_filename\n";
	open F,">$dep_filename" or die "Can't open $dep_filename";
	
	print F $result;
	close F;
}
#######################################################################################################################
#######################################################################################################################
#######################################################################################################################
sub create_workspace_header
{
	return <<__STRING__
Microsoft Developer Studio Workspace File, Format Version 6.00
# WARNING: DO NOT EDIT OR DELETE THIS WORKSPACE FILE!
__STRING__
;
}

sub create_workspace_project
{
	my $lib = shift;
	my $fullpath = shift;
	my $dependence =shift;
	return <<__STRING__
###############################################################################
Project: "$lib"=$fullpath - Package Owner=<4>

Package=<5>
{{{
}}}

Package=<4>
{{{
$dependence
}}}
__STRING__
;
}
sub create_workspace_dependence
{
	my $lib = shift;
	return <<__STRING__
    Begin Project Dependency
    Project_Dep_Name $lib
    End Project Dependency
__STRING__
;
}
sub create_workspace
{
	my $workspace_filename = shift;
	my $lib_list = shift;

	my $result = '';

	$result .= create_workspace_header();

	my $dependence = '';
	foreach my $lib (@$lib_list) {
		$dependence .= create_workspace_dependence($lib);
	}
	#($dependence .= create_workspace_dependence("mcddll")) if ((-d "..\\ps\\mcddll") && (-e "..\\ps\\mcddll\\mcddll.dsp"));

	if($workspace_filename eq 'MoDIS_Custom.dsw') {
		$result .= create_workspace_project("MoDIS",".\\MoDIS\\MoDIS_Custom.dsp",$dependence);
		system("attrib +r .\\MoDIS_Custom.ncb") if (-e ".\\MoDIS_Custom.ncb");
	} else {
		$result .= create_workspace_project("MoDIS",".\\MoDIS\\MoDIS.dsp",$dependence);
		system("attrib +r .\\MoDIS.ncb") if (-e ".\\MoDIS.ncb");
	}

	foreach my $lib (@$lib_list) {
		$result .= create_workspace_project($lib,".\\$lib\\$lib.dsp",'');
	}
	#($result .= create_workspace_project("mcddll","..\\ps\\mcddll\\mcddll.dsp",'')) if ((-d "..\\ps\\mcddll") && (-e "..\\ps\\mcddll\\mcddll.dsp"));

	print "Write $workspace_filename\n";
	open F,">$workspace_filename" or die "Can't open $workspace_filename";
	print F $result;
	close F;

}
sub update_lib_project
{
	my $old_project = shift;
	my $new_project = shift;
	my $release_MoDIS_lib = shift;
	my $list = shift;

	open F,"<$old_project" or die "Can't open $old_project";
	my $content = join('',<F>);
	close F;

	#$content =~ s/# Begin Group "libs".*?# End Group//gs;
  $content =~ s/MoDIS_lib/$release_MoDIS_lib/g;
  if ($content =~ /# Begin Group "libs".*?# End Group/gs) {
	  my $t;
	  foreach my $line (split('\n',$list))
	  {
		$t .= "# Begin Source File\n";
		$t .= "SOURCE=$line\n";
		$t .= "# End Source File\n";
	  }
        
	  $content =~ s/# End Group\n# End Target/$t# End Group\n# End Target/;

  } else {
	  my $t = "# Begin Group \"libs\"\n# PROP Default_Filter \"\"\n";
	  foreach my $line (split('\n',$list))
	  {
		$t .= "# Begin Source File\n";
		$t .= "SOURCE=$line\n";
		$t .= "# End Source File\n";
	  }
	  $t .= "# End Group\n";
        
	  $content =~ s/# End Target/$t# End Target/;
	}

	open F,">$new_project" or die "Can't write $new_project";
	print F $content;
	close F;
}
return 1;
