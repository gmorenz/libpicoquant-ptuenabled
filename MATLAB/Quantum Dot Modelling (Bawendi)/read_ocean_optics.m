function spectrum = read_ocean_optics(filename)
%% 5.38 Module 10
% Massachusetts Institute of Technology
%
% Thomas Bischof
% 18 February 2011
%
% Given a text file generated by Ocean Optics' Spectra Suite software,
% this routine determines whether or not the file has a header and reads in
% the spectrum to an Nx2 float array.

% First, read the file into an array containing each line.
data = textread(filename, '%s', 'delimiter', '\n');
height = length(data);

firstline = char(data(1));

if strcmp('Spec', firstline(1:4))
    % The file appears to have a header, so we have to choose our stop
    % and start points appropriately
    start = 18;
    stop = height-2;
else
    % No header, just a plain tab-delmited file
    start = 1;
    stop = height;
end

% Now, we know where the data lie in the file, so use the delmited file
% reader to extract the values we care about.
spectrum = dlmread(filename, '', [start, 0, stop, 1]);

end