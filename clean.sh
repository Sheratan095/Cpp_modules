for dir in ./*/*/; do
	make -C "$dir" fclean > /dev/null 2>&1
done

echo "Clean operation completed successfully!"
