out_dir := bin
target  := ${out_dir}/success

main: setup
	g++ main.cc -o ${target}
	cp -t ${out_dir} script/*

setup:
	mkdir -p ${out_dir}

clean:
	rm -rf ${out_dir}
