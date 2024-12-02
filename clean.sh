for dir in ./*/*/; do
	make -C "$dir" fclean
done
