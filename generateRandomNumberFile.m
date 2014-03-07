#!/opt/local/bin/octave -q --interactive
arguments=argv;
if(size(arguments,1) < 4)
	disp('usage <script> filename maxvalue from to') 
else
	file = fopen (arguments{1}, "w", "ieee-le");
	rnd=unidrnd(str2num(arguments{2}),str2num(arguments{3}),str2num(arguments{4}));	
	fwrite(file,rnd,'int');
	fclose(file);
	printf('file %s has been generated :)\n\r',arguments{1});
end
