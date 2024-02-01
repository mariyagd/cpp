# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    class.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pudry <pudry@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 16:25:43 by pudry             #+#    #+#              #
#    Updated: 2024/02/01 11:13:52 by pudry            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import os

def write_header(arg, path):
	f = open(path + "/" + arg + ".hpp", "a")

	f.write("#ifndef __" + arg.upper() + "__HPP\n")
	f.write("# define __" + arg.upper() + "__HPP\n\n")

	f.write("# include <iostream>\n\n")

	f.write("class " + arg)
	f.write("\n{\n")
	f.write("\tpublic:\n")
	f.write("\t\t" + arg + "(void);\n")
	f.write("\t\t~" + arg + "(void);\n")
	f.write("\t\t" + arg +"(const " + arg + " &src);\n")
	f.write("\t\t" + arg +"\t&operator=(const " + arg + " &src);\n\n")
	f.write("\tprivate:\n\n")
	f.write("};\n\n")
	f.write("#endif\n")

	f.close()

def write_cpp(arg, path):
	f = open(path + "/" + arg + ".cpp", "a")

	f.write("#include \"" + arg + ".hpp\"\n\n")

	f.write(arg +"\t&" + arg + "::operator=(const " + arg + " &src)\n{\n\t\n}\n\n")
	f.write(arg + "::" + arg + "(const " + arg + " &src)\n{\n\t\n}\n\n")
	f.write(arg + "::~" + arg + "(void){}\n\n")
	f.write(arg + "::" + arg + "(void){}\n")
	f.close()


for args in sys.argv[1:]:
	write_header(args, os.environ['PWD'])
	write_cpp(args, os.environ['PWD'])


