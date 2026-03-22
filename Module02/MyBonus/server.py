import http.server
import socketserver
import subprocess
import json

PORT = 8000

class Handler(http.server.SimpleHTTPRequestHandler):
    def do_POST(self):
        if self.path == '/check':
            content_length = int(self.headers['Content-Length'])
            post_data = self.rfile.read(content_length)
            data = json.loads(post_data)
            
            args = [
                './a.out',
                str(data['a']['x']), str(data['a']['y']),
                str(data['b']['x']), str(data['b']['y']),
                str(data['c']['x']), str(data['c']['y']),
                str(data['p']['x']), str(data['p']['y'])
            ]
            
            try:
                result = subprocess.run(args, capture_output=True, text=True)
                output = result.stdout.strip()
            except Exception as e:
                output = "ko"
                
            self.send_response(200)
            self.send_header('Content-type', 'text/plain')
            self.send_header('Access-Control-Allow-Origin', '*')
            self.end_headers()
            self.wfile.write(output.encode())
        else:
            self.send_response(404)
            self.end_headers()

    def do_OPTIONS(self):
        self.send_response(200)
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'GET, POST, OPTIONS')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')
        self.end_headers()

with socketserver.TCPServer(("", PORT), Handler) as httpd:
    print("Serving at port", PORT)
    httpd.serve_forever()
