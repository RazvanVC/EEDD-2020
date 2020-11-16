.PHONY: clean All

All:
	@echo "----------Building project:[ PECL1 - Debug ]----------"
	@cd "PECL1" && "$(MAKE)" -f  "PECL1.mk"
clean:
	@echo "----------Cleaning project:[ PECL1 - Debug ]----------"
	@cd "PECL1" && "$(MAKE)" -f  "PECL1.mk" clean
