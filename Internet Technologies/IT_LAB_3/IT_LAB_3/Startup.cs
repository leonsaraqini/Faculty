using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(IT_LAB_3.Startup))]
namespace IT_LAB_3
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
