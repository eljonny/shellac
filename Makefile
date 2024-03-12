.PHONY: clean All

All:
	@echo "----------Building project:[ shellac - Debug ]----------"
	@"$(MAKE)" -f  "shellac.mk"
clean:
	@echo "----------Cleaning project:[ shellac - Debug ]----------"
	@"$(MAKE)" -f  "shellac.mk" clean
