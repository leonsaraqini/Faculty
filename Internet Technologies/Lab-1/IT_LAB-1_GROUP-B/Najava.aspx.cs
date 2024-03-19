using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace IT_LAB_1
{
    public partial class Najava : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void addInfo_Click(object sender, EventArgs e)
        {
            Session["Email"] = tbEmail.Text;
            Response.Redirect("Glasaj.aspx");
        }
    }
}