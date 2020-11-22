#!/bin/bash

declare log="norminette.txt"
declare norminette="~/.norminette/norminette.rb"

main()
{
	[[ -f $log ]] && rm "${log}"
	"${norminette}" src includes 2>/dev/null > "${log}"
	cat "${log}"
	if cat "${log}" | grep "Error"; then
		exit 1
	else
		exit 0
	fi
}

main